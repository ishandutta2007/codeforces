#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long int llint;
typedef pair < int,int> pii;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int M = 1e6 + 500;

char s[M];
int nxt[M],prev[M],muc[M],n,fir = 0,cur,lst,ty[M];

int main(){
    scanf("%[^\n]",s);
    n = strlen(s);
    for(int i = 0;i<n;){
        char c = s[i];
        int oj = i;
        while(i < n && s[i] == c)
            i++;
        ty[cur] = c;
        muc[cur++] = i - oj;
        nxt[cur-1] = cur;
    }
    lst = cur;
    int sol = 0;
    while(fir != lst && nxt[fir] != lst){
        for(int i = fir;i!=lst;i=nxt[i]){
            muc[i]--;
            if(i != fir && nxt[i] != lst) muc[i]--;
        }
        while(fir != lst && muc[fir] < 1) fir = nxt[fir];
        for(int i = fir;i!=lst;i=nxt[i]){
            while(nxt[i] != lst){
                if(muc[nxt[i]] < 1){
                    nxt[i] = nxt[nxt[i]];
                }
                else if(ty[i] == ty[nxt[i]]){
                    muc[i] += muc[nxt[i]];
                    nxt[i] = nxt[nxt[i]];
                }
                else{
                    break;
                }
            }
        }
        sol++;
    }
    printf("%d\n",sol);
}