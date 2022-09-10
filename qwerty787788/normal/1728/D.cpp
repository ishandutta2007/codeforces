# include <bits/stdc++.h>
# define ll long long
 
using namespace std;
 
map <pair <int, int>, int> mal;
map <pair <char, pair <int, int>>, int> mob;
string st;
// 1 alice, 2 bob, 3 draw
 
int aturn (int l, int r);
int bturn (char ch, int l, int r);
 
int aturn (int l, int r)
{
    if (mal.count ({l, r}))
        return mal[{l, r}];
    if (r == l + 1)
    {
        //cout << st[l] << st[r] << endl;
        if (st[l] == st[r])
        {
            mal[{l, r}] = 3;
            return 3;
        }
        mal[{l, r}] = 1;
        return 1;
    }
    int fst = bturn (st[l], l + 1, r);
    int snd = bturn (st[r], l, r - 1);
    if (fst == 1 || snd == 1)
    {
        mal[{l, r}] = 1;
        return 1;
    }
    if (fst == 3 || snd == 3)
    {
        mal[{l, r}] = 3;
        return 3;
    }
    mal[{l, r}] = 2;
    return 2;
}
 
int bturn (char ch, int l, int r)
{
    if (mob.count ({ch, {l, r}}))
        return mob[{ch, {l, r}}];
    if (l == r)
    {
        if (st[l] < ch)
        {
            mob[{ch, {l, r}}] = 2;
            return 2;
        }
        if (st[l] > ch)
        {
            mob[{ch, {l, r}}] = 1;
            return 1;
        }
        mob[{ch, {l, r}}] = 3;
        return 3;
    }
    int fst = aturn (l + 1, r);
    int snd = aturn (l, r - 1);
    if (fst == 2 || snd == 2 || (fst == 3 && st[l] < ch) || (snd == 3 && st[r] < ch))
    {
        mob[{ch, {l, r}}] = 2;
        return 2;
    }
    if ((fst == 3 && st[l] == ch) || (snd == 3 && st[r] == ch))
    {
        mob[{ch, {l, r}}] = 3;
        return 3;
    }
    mob[{ch, {l, r}}] = 1;
    return 1;
}
 
void solve ()
{
    mal.clear();
    mob.clear();
    cin >> st;
    int res = aturn (0, st.length() - 1);
    int ss = 0;
    for (auto x : mal) ss++;
    for (auto x : mob) ss++;
    assert(ss <= 3000000);
    if (res == 1)
    {
        cout << "Alice\n";
        return;
    }
    if (res == 2)
    {
        cout << "Bob\n";
        return;
    }
    if (res == 3)
    {
        cout << "Draw\n";
        return;
    }
}
 
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}