#include <bits/stdc++.h>
#define FOR(i, j, k) for (int i = j; i <= k; i ++)
#define FORD(i, j, k) for (int i = j; i >= k; i --)
#define mn 1000
#define maxC 1000000007
#define base 100007
#define F first
#define S second

using namespace std;
int n, a, b, k, f, cnt = 0, ans = 0;
string from, to; int fromId = 0, toId = 0;
map< pair<int, int> , int > cost;

struct trie
{
    int id;
    trie* child[52];

    trie()
    {
        id = 0;
        FOR(i, 0, 51)
            child[i] = NULL;
    }
} root;

int encode(char c)
{
    if ('a' <= c && c <= 'z')
        return c - 'a';
    return c - 'A' + 26;
}

int getId(string& s)
{
    trie* p = &root;
    FOR(i, 0, int(s.size()) - 1)
    {
        int z = encode(s[i]);
        if (p->child[z] == NULL)
            p->child[z] = new trie();
        p = p->child[z];
    }
    if (!p->id)
        p->id = ++ cnt;
    return p->id;
}

void setup()
{
    cin >> n >> a >> b >> k >> f;
    FOR(i, 1, n)
    {
        cin >> from >> to;
        int price = a;
        fromId = getId(from);
        if (fromId == toId)
            price = b;
        toId = getId(to);

        pair<int, int> p = make_pair(fromId, toId);
        if (p.F > p.S)
            swap(p.F, p.S);
        cost[p] += price;
        ans += price;
    }
}

vector<int> temp;

void xuly ()
{
    for(map< pair<int, int> , int >::iterator i = cost.begin(); i != cost.end(); i ++)
        temp.push_back(i->S);
    sort(temp.begin(), temp.end());
    FORD(i, int(temp.size()) - 1, 0)
    {
        if (!k || temp[i] <= f)
            break;
        ans -= temp[i];
        ans += f;
        k --;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    setup ();
    xuly ();
    return 0;
}