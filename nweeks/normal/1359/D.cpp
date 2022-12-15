#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

template<class T>
struct rangeAddSeg
{
    int nb_elem;
    int LIM;
    vector<T> seg;
    int deb;

    rangeAddSeg(int N)
    {
        int p(0);
        while ((1<<p) < N)
            ++p;
        deb = (1<<p)-1;
        seg.resize((1<<(p+1)));
        for (int i(0); i < SZ(seg); ++i)
            seg[i] = 1e9;
    }

    T query(int lo, int up)
    {
        lo += deb, up += deb;
        T ans = 1e9;
        while (lo < up)
        {
            if (lo%2==0)
                ans = min(ans, seg[lo]);
            lo /= 2;
            if (up%2)
                ans = min(ans, seg[up]);
            up = (up-2)/2;
        }
        if (lo==up)
            ans = min(ans, seg[lo]);
        return ans;
    }

    void update(int id, T val)
    {
        id += deb;
        seg[id] = val;
        while (id)
        {
            id = (id-1)/2;
            seg[id] = min(seg[2*id+1], seg[2*id+2]);
        }
    }
};

const int MAXN = 1e5+1;

rangeAddSeg<int> fenPref = rangeAddSeg<int>(MAXN);
rangeAddSeg<int> fenSuff = rangeAddSeg<int>(MAXN);

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int nb_elem;
    cin >> nb_elem;
    vector<int> arr(nb_elem+1);
    for (int i(1); i <= nb_elem; ++i)
        cin >> arr[i];

    vector<int> prefSum(nb_elem+1);
    for (int i(1); i <= nb_elem; ++i)
        prefSum[i] = arr[i] + prefSum[i-1];
    for (int i(0); i <= nb_elem; ++i)
    {
        fenPref.update(i, prefSum[i]);
        fenSuff.update(i, -prefSum[i]);
    }
    vector<int> bef(nb_elem+1), aft(nb_elem+1);
    bef[1] = 0;
    for (int i(2); i <= nb_elem; ++i)
    {
        int j = i-1;
        while (j and arr[j] <= arr[i])
            j = bef[j];
        bef[i] = j;
    }
    aft[nb_elem] = nb_elem+1;
    for (int i(nb_elem-1); i >= 0; --i)
    {
        int j = i+1;
        while (j<=nb_elem and arr[j] <= arr[i])
            j = aft[j];
        aft[i] = j;
    }

    int ans(-1e9);
    for (int i(1); i <= nb_elem; ++i)
        ans = max(ans, -arr[i] - fenPref.query(bef[i], i-1) - fenSuff.query(i, aft[i]-1));
    cout << ans << endl;
}