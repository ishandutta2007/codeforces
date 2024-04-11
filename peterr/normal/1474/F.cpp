#include <bits/stdc++.h>

using namespace std;

struct Event
{
    long long pos;
    int ind;
    bool type;
};

const int MOD = 998244353;
const int MAXN = 50;
long long d[MAXN];
bool active[MAXN];
bool inc[MAXN];
vector<pair<long long, long long>> segs;
vector<Event> events;
int cnt[MAXN];
int root[MAXN];

void printMat(const vector<vector<int>> &mat)
{
    int n = (int) mat.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << "\t\n"[j == n - 1];
}

void add(int &x, int y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
    if (x < 0)
        x += MOD;
}

void matMult(const vector<vector<int>> &mat1, const vector<vector<int>> &mat2, vector<vector<int>> &res)
{
    int n = (int) mat1.size();
    vector<vector<int>> temp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            for (int j = 0; j < n; j++)
                add(temp[i][j], (int) ((long long) mat1[i][k] * mat2[k][j] % MOD));
    copy(temp.begin(), temp.end(), res.begin());
}

void matExp(const vector<vector<int>> &mat, vector<vector<int>> &res, long long e)
{
    vector<vector<int>> temp(mat);
    for (int i = 0; i < (int) res.size(); i++)
        fill(res[i].begin(), res[i].end(), 0), res[i][i] = 1;
    while (e)
    {
        if (e & 1)
            matMult(res, temp, res);
        e >>= 1;
        matMult(temp, temp, temp);
    }
}

int sign(long long x)
{
    if (x > 0)
        return 1;
    else if (x < 0)
        return -1;
    return 0;
}

void compress(int &n)
{
    int ptr1 = -1;
    int ptr2 = 0;
    while (ptr2 < n)
    {
        if (d[ptr2] == 0)
            ptr2++;
        else if (ptr1 > -1 && sign(d[ptr2]) * sign(d[ptr1]) > 0)
        {
            d[ptr1] += d[ptr2];
            //cout << "VAL of ptr " << ptr1 << " " << d[ptr1] << endl;
            ptr2++;
        }
        else
        {
            ptr1++;
            d[ptr1] = d[ptr2];
            ptr2++;
        }
    }
    n = ptr1 + 1;
}

void stepNxt(vector<int> &vec)
{
    int n = (int) vec.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (!inc[i])
            vec[i] = 0;
        for (int j = root[i]; j < i; j++)
            add(vec[i], vec[j]);
    }
}

void vectorMult(const vector<vector<int>> &mat, vector<int> &vec)
{
    int n = (int) mat.size();
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            add(temp[i], (int) ((long long) vec[j] * mat[i][j] % MOD));
        }
    }
    copy(temp.begin(), temp.end(), vec.begin());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    compress(n);
    if (n == 0)
    {
        cout << "1 1\n";
        return 0;
    }
    if (n == 1 && d[0] < 0)
    {
        cout << "1 " << abs(d[0] - 1) % MOD << "\n";
        return 0;
    }
    /*
    for (int i = 0; i < n; i++)
        cout << "new " << i << " " << d[i] << endl;
    */
    long long cur = d[0];
    inc[0] = d[0] > 0;
    segs.push_back({min(0LL, d[0]), max(0LL, d[0])});
    for (int i = 1; i < n; i++)
    {
        inc[i] = d[i] > 0;
        if (d[i] > 0)
        {
            segs.push_back({cur + 1, cur + d[i]});
        }
        else
        {
            segs.push_back({cur + d[i], cur - 1});
        }
        cur += d[i];
    }
    /*
    cout << "SEGS" << endl;
    for (pair<long long, long long> pr : segs)
        cout << pr.first << " " << pr.second << endl;
    cout << "/SEGS" << endl;
    */
    for (int i = 0; i < n; i++)
    {
        events.push_back({segs[i].first, i, true});
        events.push_back({segs[i].second + 1, i, false});
    }
    sort(events.begin(), events.end(), [&] (const Event& a, const Event& b) { return a.pos != b.pos ? a.pos < b.pos : a.ind < b.ind; });
    /*
    cout << "EVENTS" << endl;
    for (Event e : events)
        cout << e.pos << " " << e.ind << " " << e.type << endl;
    cout << "/EVENTS" << endl;
    */
    fill(root, root + n, -1);
    long long curPos = events[0].pos;
    int ptr = 0;
    vector<int> vec(n);
    while (ptr < (int) events.size())
    {
        long long newPos = events[ptr].pos;
        if (ptr > 0)
        {
            vector<vector<int>> mat(n, vector<int>(n));
            for (int i = 0; i < n; i++)
            {
                if (!active[i] || root[i] == -1)
                    continue;
                for (int j = root[i]; j < i + inc[i]; j++)
                {
                    if (!active[j])
                        continue;
                    mat[i][j] = 1;
                }
            }
            matExp(mat, mat, newPos - curPos - 1);
            vectorMult(mat, vec);
            for (int i = 0; i < n; i++)
            {
                if (active[i])
                    cnt[i] = vec[i];
            }
            stepNxt(vec);
        }
        while (ptr < (int) events.size() && events[ptr].pos == newPos)
        {
            active[events[ptr].ind] = events[ptr].type;
            if (events[ptr].type && root[events[ptr].ind] == -1)
            {
                for (int i = events[ptr].ind; i < n && root[i] == -1; i++)
                    root[i] = events[ptr].ind;
            }
            if (events[ptr].type && events[ptr].pos == segs[root[events[ptr].ind]].first)
                vec[events[ptr].ind] = 1;
            ptr++;
        }
        curPos = newPos;
        for (int i = 0; i < n; i++)
        {
            if (!active[i])
                vec[i] = 0;
        }
    }
    int ans = 0;
    long long len = 0;
    for (int i = 0; i < n; i++)
    {
        //cout << "root " << i << " " << root[i] << endl;
        if (!inc[i])
            continue;
        if (segs[i].second - segs[root[i]].first + 1 < len)
            continue;
        if (segs[i].second - segs[root[i]].first + 1 > len)
            ans = 0;
        len = max(len, segs[i].second - segs[root[i]].first + 1);
        add(ans, cnt[i]);
    }
    cout << len << " " << ans << "\n";
    return 0;
}