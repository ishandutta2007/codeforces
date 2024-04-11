#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define f first
#define s second

int main(){

    int n;
    cin >> n;
    string s;
    int t,m;
    m = 0;
    while(cin >> s){
        t = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] < 95){
                t++;
            }
        }
        m = max(t,m);
    }
    cout << m;
    return 0;
}