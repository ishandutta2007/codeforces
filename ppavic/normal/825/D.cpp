#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

typedef long long int llint;
typedef pair < int,int> pii;

const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int off = 1<<18;
const int MOD = 1e9 + 7;

char s[M],t[M],up[M];

int cnt[500],ed,siz1,siz2,cnt2 = 0;

int main(){
    scanf("%s",s);
    scanf("%s",t);
    siz1 = strlen(s);
    siz2 = strlen(t);
    for(int i = 0;i<siz1;i++){
        cnt[s[i]]++;
    }
    while(!ed){
        for(int i = 0;i<siz2;i++){
            if(cnt[t[i]] > 0){
                cnt[t[i]]--;
            }
            else if(cnt['?'] > 0){
                cnt['?']--;
                up[cnt2] = t[i];cnt2++;
            }
            else{
                ed = 1;
                break;
            }
        }
    }

    int j = 0;
    for(int i = 0;i<siz1;i++){
        if(s[i] == '?') cout << up[j++];
        else     cout << s[i];
    }
    cout << endl;
}