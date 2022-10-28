#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 18;
int n , m;
char str[N];
int taken[N];
string ans = "";
int main(){
    scanf("%d" , &m);
    scanf("%s" , str + 1);
    n = strlen(str + 1);
    for(int i = 1 ; i <= n ; ++i){
        taken[i] = 0;
    }
    for(char c = 'a' ; c <= 'z' ; ++c){
        int last = 0;
        int idx = -1;
        vector < int > tmp;
        tmp.clear();
        bool rekt = 0;
        for(int i = 1 ; i <= n ; ++i){
            if(str[i] == c){
                idx = i;
            }
            if(taken[i]){
                last = i;
            }
            if(i - last >= m){
                last = idx;
                if(i - idx >= m){
                    rekt = 1;
                    break;
                }
                tmp.emplace_back(idx);
            }
        }
        if(rekt){
            for(int i = 1 ; i <= n ; ++i){
                if(str[i] == c){
                    ans += c;
                    taken[i] = 1;
                }
            }
        }
        else{
            for(auto it : tmp){
                ans += c;
            }
            break;
        }
    }
    cout << ans << endl;
}