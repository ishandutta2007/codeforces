#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define maxn 300300
#define ll long long
#define debug 
using namespace std;

int main(){
    set<pii> s[2];
    multiset<int> m[2];
    int w,h,n;
    scanf("%d%d%d",&w,&h,&n);
    s[0].insert(pii(w,1));
    s[1].insert(pii(h,1));
    m[0].insert(w);
    m[1].insert(h);
    while(n--){
        char ch;
        int a;
        scanf(" %c %d",&ch,&a);
        int y = (ch == 'H'); 
        pii u = *s[y].lower_bound(pii(a,-1));
        s[y].erase(u);
        m[y].erase(m[y].find(u.first-u.second+1));
        s[y].insert(pii(a,u.second));
        s[y].insert(pii(u.first,a+1));
        m[y].insert(a-u.second+1);
        m[y].insert(u.first-a);
        printf("%lld\n",(ll) (*--m[0].end()) * (*--m[1].end()));
    }
}