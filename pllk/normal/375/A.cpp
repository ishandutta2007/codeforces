#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int pois[10];

int main() {
    string a;
    int nollat = 0;
    cin>>a;
    for(int i = 0; i < a.size(); ++i) {
        a[i] -= '0';
        if(a[i] == 1 || a[i] == 6 || a[i] == 8 || a[i] == 9) {
            if(!pois[a[i]]) {
                pois[a[i]] = 1;
                a.erase(a.begin() + i);
                --i;
            }
        }  
    }
    sort(a.begin(), a.end());
    if(a.size() && a.back() == 0) {
        nollat = a.size();
        a.clear();

    }
    int cute = 10000;
    cute %= 7;
    int qwe = 0;
    for(int i = 0; i < a.size(); ++i) {
        qwe += (a[i]*cute)%7;
        cute *= 10;
        cute %= 7;
        qwe %= 7;
    }
    //cout<<qwe<<'\n';
    for(auto & x: a) {
        x += 48;
    }
    for(int i = a.size()-1; i >= 0; --i) {
        cout<<a[i];
    }
    vector<int> lol = {1, 6, 8, 9};
    do {
        int q = 0;
        for(int i = 3; i >= 0; --i) {
            q += (int)(pow(10, 3-i)+0.5)* lol[i];
        }
        if((qwe+q)%7 == 0) {
        //    cout<<'\n'<<q<<'\n';
            for(auto x: lol) cout<<x;
            goto jee;
        }
       // cout<<(q%7)<<'\n';

    } while(next_permutation(lol.begin(), lol.end()));
    jee:;
    for(int i =0; i < nollat; ++i) {
        cout<<0;
    }
    cout<<'\n';
}