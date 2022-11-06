#include <bits/stdc++.h>

using namespace std;

const long long INF = 1E15;
const int MAXN = 1 << 20;
tuple<int, int, int> a[MAXN];
pair<long long, int> seg[2 * MAXN];
long long lz[2 * MAXN];
map<int, int> encode;
int decode[MAXN];

void prop(int ind)
{
    seg[ind].first += lz[ind];
    if (ind < MAXN)
    {
        lz[ind * 2] += lz[ind];
        lz[ind * 2 + 1] += lz[ind];
    }
    lz[ind] = 0;
}

void upd(int l, int r, int amt, int lb=0, int ub=MAXN-1, int ind=1)
{
    prop(ind);
    if (ub < l || lb > r)
        return;
    if (lb >= l && ub <= r)
        lz[ind] += amt;
    else
    {
        int mid = (lb + ub) / 2;
        upd(l, r, amt, lb, mid, ind * 2);
        upd(l, r, amt, mid + 1, ub, ind * 2 + 1);
        prop(ind * 2);
        prop(ind * 2 + 1);
        seg[ind] = max(seg[ind * 2], seg[ind * 2 + 1]);
    }
}

pair<long long, int> query(int l, int r, int lb=0, int ub=MAXN-1, int ind=1)
{
    prop(ind);
    if (ub < l || lb > r)
        return {-INF, -1};
    if (lb >= l && ub <= r)
        return seg[ind];
    int mid = (lb + ub) / 2;
    return max(query(l, r, lb, mid, ind * 2), query(l, r, mid + 1, ub, ind * 2 + 1));
}

void build(int ind, int n)
{
    if (ind >= MAXN)
        seg[ind] = {(ind - MAXN >= n ? -INF : -decode[ind - MAXN]), ind - MAXN};
    else
    {
        build(ind * 2, n);
        build(ind * 2 + 1, n);
        seg[ind] = max(seg[ind * 2], seg[ind * 2 + 1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> get<0>(a[i]) >> get<1>(a[i]) >> get<2>(a[i]);
        if (get<0>(a[i]) > get<1>(a[i]))
            swap(get<0>(a[i]), get<1>(a[i]));
        encode[get<0>(a[i])] = 0;
        encode[get<1>(a[i])] = 0;
    }
    int cnt = 0;
    for (auto &it : encode)
    {
        decode[cnt] = it.first;
        it.second = cnt++;
    }
    build(1, cnt);
    for (int i = 0; i < n; i++)
    {
        get<0>(a[i]) = encode[get<0>(a[i])];
        get<1>(a[i]) = encode[get<1>(a[i])];
        //cout << "New " << get<0>(a[i]) << " " << get<1>(a[i]) << endl;
    }
    sort(a, a + n);
    long long ans = 0;
    int x1 = 1E9 + 1;
    int x2 = 1E9 + 1;
    for (int i = 0; i < n; i++)
    {
        upd(get<1>(a[i]), MAXN - 1, get<2>(a[i]));
    }
    //pair<long long, int> test = query(0, MAXN - 1);
    //cout << "test " << test.first << " " << test.second << endl;
    int ptr = 0;
    while (ptr < n)
    {
        int curl = get<0>(a[ptr]);
        pair<long long, int> pr = query(curl, MAXN - 1);
        //cout << "currently at " << curl << " " << decode[curl] << endl;
        //cout << pr.first << " " << pr.second << endl;
        pr.first += decode[curl];
        //cout << pr.first << " " << pr.second << endl;
        if (pr.first > ans)
        {
            ans = pr.first;
            x1 = decode[curl];
            x2 = decode[pr.second];
        }

        while (ptr < n && get<0>(a[ptr]) == curl)
        {
            upd(get<1>(a[ptr]), MAXN - 1, -get<2>(a[ptr]));
            ptr++;
        }
    }
    cout << ans << "\n";
    cout << x1 << " " << x1 << " " << x2 << " " << x2 << "\n";
    return 0;
}