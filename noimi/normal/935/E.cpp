#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int const N = 11000;
char s[N];
int pos;
using P = pair<int,int> ;
vector<P> expr();
int number(){
    return s[pos++]-'0';
}
vector<P> factor(){
    if(s[pos] == '('){
        pos++;
        auto res = expr();
        assert(s[pos]==')');
        pos++;
        return res;
    }
    else{
        int num = number();
        return {{num,num}};
    }
}
vector<P> expr(){
    auto res = factor();
    for(;;){
        if(s[pos]!='?')break;
        pos++;
        auto r = factor();
        vector<P> nxt(res.size()+r.size(),{-INT_MAX,INT_MAX});
        rep(i,res.size())rep(j,r.size()){
            nxt[i+j].first = max(nxt[i+j].first,res[i].first-r[j].second);
            nxt[i+j].second = min(nxt[i+j].second,res[i].second-r[j].first);
            nxt[i+j+1].first = max(nxt[i+j+1].first,res[i].first+r[j].first);
            nxt[i+j+1].second = min(nxt[i+j+1].second,res[i].second+r[j].second);
        }
        res = nxt;
    }
    return res;
}
main(){
    scanf("%s",s);
    int p,q;cin>>p>>q;
    cout << expr()[p].first << endl;
}