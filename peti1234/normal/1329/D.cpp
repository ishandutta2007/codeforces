#include <bits/stdc++.h>

using namespace std;
#define lsb(i) ((i) & -(i))
const int c=200002;
int w, n, db[32], dp[c], cnt, maxi, pos;
bool tor[c];
string s;
vector<pair<int, int> > sz, h;
vector<int> ss;
int ask(int a) {
    int sum=0;
    while(a) sum+=dp[a], a-=lsb(a);
    return sum;
}
void pl(int a, int b) {
    while(a<=n) dp[a]+=b, a+=lsb(a);
}
void add(int a, int b) {
    int x=a-ask(a), y=b-ask(b);
    cout << x << " " << y << "\n";
    pl(a, y-x+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s; n=s.size();
        pos=0, maxi=0, cnt=0, sz.clear(), h.clear(), ss.clear();
        for (int i=0; i<30; i++) db[i]=0;
        for (int i=0; i<=n; i++) tor[i]=0, dp[i]=0;
        for (int i=0; i<n-1; i++) if (s[i]==s[i+1]) {
            int x=s[i]-'a'+1;
            if (s[i]==s[i+1]) {
                db[x]++, cnt++; if (db[x]>db[pos]) pos=x;
                sz.push_back({x, i+1});
            }
        }
        maxi=db[pos];
        cout << max(maxi, (cnt+1)/2)+1 << "\n";
        for (int i=0; i<sz.size(); i++) {
            int x=sz[i].first, p2=sz[i].second;
            if (ss.size()>0) {
                int id=ss.back(), y=sz[id].first, p1=sz[id].second;
                if (x!=y && 2*maxi<cnt) {
                    tor[id]=1, tor[i]=1, db[x]--, db[y]--, cnt-=2, ss.pop_back();
                    add(p1+1, p2);
                }
                for (int i=0; i<30; i++) if (db[i]>db[pos]) pos=i;
                maxi=db[pos];
            }
            if (!tor[i]) ss.push_back(i);
        }
        for (int i=0; i<sz.size(); i++) {
            if (!tor[i]) {
                int x=sz[i].first, p2=sz[i].second, jo=0;
                if (h.size()>0) {
                    int y=h.back().first, p1=h.back().second;
                    if (x!=y && (x==pos || y==pos)) jo=1, add(p1+1, p2), h.pop_back();
                }
                if (!jo) h.push_back({x, p2});
            }
        }
        for (int i=0; i<h.size(); i++) add(h[i].second+1, h[i].second+1);
        add(1, n);
    }
    return 0;
}