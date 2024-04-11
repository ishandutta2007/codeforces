#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<int> kmp(string h){
    vector<int> pp(h.size());
    int p = 0;
    for(int i = 1; i < h.size(); i ++ ){
        p = pp[i - 1];
        while(p > 0 && h[p] != h[i]){
            p = pp[p-1];
        }
        if(h[p] == h[i])
            pp[i]=p+1;
    }
    return pp;
}

int main(){
    fastIO;
    string s, t;
    cin >> s >> t;
    vector<int> res = kmp(t);
    int d0 = 0, d1 = 0;
    for(auto x : s){
        if(x == '0') d0 ++ ;
        else d1 ++ ;
    }
    for(auto x : t){
        if(x == '0'){
            if(d0 > 0){
                d0 -- ;
                cout << "0";
            }
            else if(d1 > 0){
                d1 -- ;
                cout << "1";
            }
        }
        else{
            if(d1 > 0){
                d1 -- ;
                cout << "1";
            }
            else if(d0 > 0){
                d0 -- ;
                cout << "0";
            }
        }
    }
    int pf = res.back();
    while(d0 > 0 || d1 > 0){
        if(t[pf] == '0'){
            if(d0 > 0){
                d0 -- ;
                cout << "0";
            }
            else if(d1 > 0){
                d1--;
                cout << "1";
            }
        }
        else{
            if(d1 > 0){
                d1 --;
                cout << "1";
            }
            else if(d0 > 0){
                d0 -- ;
                cout << "0";
            }
        }
        pf ++ ;
        if(pf == res.size())
            pf = res.back();
    }
    return 0;
}