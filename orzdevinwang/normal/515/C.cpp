#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair 
const int N = 1e5 + 7;
int n, cnt[10];
char s[N];
int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    L(i, 1, n) {
        if(s[i] == '1') ;
        else if(s[i] == '2') cnt[2] ++;
        else if(s[i] == '3') cnt[3] ++;
        else if(s[i] == '4') cnt[2] += 2, cnt[3]++;
        else if(s[i] == '5') cnt[5] ++;
        else if(s[i] == '6') cnt[5] ++, cnt[3] ++;
        else if(s[i] == '7') cnt[7] ++;
        else if(s[i] == '8') cnt[2] += 3, cnt[7] ++;
        else if(s[i] == '9') cnt[7] ++, cnt[2] ++ ,cnt[3] += 2;
    }
    R(i, 9, 1) L(j, 1, cnt[i]) printf("%d", i);
    return 0;
}