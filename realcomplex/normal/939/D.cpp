#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int AL = 26;
vector<int>E[AL];
vector<pair<char,char>>edg;

bool findPath(int cur,int las,int req){
    if(cur==req)
        return true;
    for(auto x : E[cur])
        if(x!=las)
            if(findPath(x,cur,req))
                return true;
    return false;
}

int main(){
    fastIO;
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    for(int i = 0;i<a.size();i++){
        if(a[i]==b[i])
            continue;
        if(findPath(a[i]-97,-1,b[i]-97))
            continue;
        edg.push_back(mp(a[i],b[i]));
        E[a[i]-97].push_back(b[i]-97);
        E[b[i]-97].push_back(a[i]-97);
    }
    cout << edg.size() << "\n";
    for(auto x : edg)
        cout << x.fi << " " << x.se << "\n";
    return 0;
}