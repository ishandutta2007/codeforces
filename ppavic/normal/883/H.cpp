#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair < int,int> pii;

const int N = 300;

int n;
int cnt[N],rec[N];
char c;
vector < string > prt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> c;
        cnt[c]++;
        rec[c]++;
    }
    for(int len = n;len>=1;len--){
        prt.clear();
        if(n%len) continue;
        for(int i = 0;i<N;i++)
            cnt[i] = rec[i];
        while(1){
            string mid = "";
            string s = "";
            for(int i = 0;i<N;i++){
                if(cnt[i]&1){
                    if(len%2 != mid.size()%2 && mid == ""){
                        cnt[i]--;
                        mid.push_back(char(i));
                    }
                }
            }
            for(int i = 0;i<N;i++){
                if(cnt[i] <= 0) continue;
                if(len%2 != mid.size()%2 && mid == ""){
                    cnt[i]--;
                    mid.push_back(char(i));
                }
            }
            for(int i = 0;i<N;i++){
                if(cnt[i] <= 0) continue;
                if(len - 2 * s.size() - mid.size() >= 2){
                    for(;cnt[i] > 1;){
                        s.push_back(char(i));cnt[i] -= 2;
                        if(len - 2 * s.size() - mid.size() < 2) break;
                    }
                }
            }
            if(mid == "" && s == "") break;
            string ss = s + mid;
            reverse(s.begin(),s.end());
            ss += s;
            prt.push_back(ss);
        }
        int gud = 1;
        for(int i = 0;i<prt.size();i++){
            if(prt[i].size() != len) gud = 0;
        }
        if(prt.size() != n / len) gud = 0;
        if(!gud) continue;
        cout << prt.size() << endl;
        for(int i = 0;i<prt.size();i++){
            cout << prt[i] << " ";
        }
        cout << endl;
        return 0;
    }
}