#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char str[200200]; int c0, c1;

void add(char x, int val = 2){
    if (x=='0') c0 += val;
    else c1 += val;
}

void solve(){
    int a, b;
    c0=0, c1=0;
    scanf("%d %d", &a, &b);
    scanf("%s", str);
    if (a&1 && b&1){
        printf("-1\n"); return;
    }
    int n = a+b;
    bool chk=0;
    vector<int> idx;
    int idx1=-1;
    for (int i=0;i<n/2;i++){
        if (abs(str[i]-str[n-1-i])==1){
            chk=1; break;
        }
        if (str[i]=='?' && str[n-1-i]=='?') idx.push_back(i);
        else if (str[i]=='?'){
            str[i] = str[n-1-i]; add(str[i], 2);
        }
        else if (str[n-1-i]=='?'){
            str[n-1-i] = str[i]; add(str[i], 2);
        }
        else add(str[i]);
    }
    if (chk){
        printf("-1\n"); return;
    }
    if (n&1){
        if (str[n/2]=='?') idx1 = n/2;
        else add(str[n/2], 1);
    }
    if (c0>a || c1>b){
        printf("-1\n"); return;
    }
    if ((a-c0)&1 && (b-c1)&1){
        printf("-1\n"); return;
    }
    for (int x:idx){
        if (a-c0>1){
            str[x] = '0', str[n-1-x] = '0';
            add(str[x]);
        }
        else{
            str[x] = '1', str[n-1-x] = '1';
            add(str[x]);
        }
    }
    if (a-c0){
        str[idx1]='0';
    }
    else if (b-c1){
        str[idx1]='1';
    }
    for (int i=0;i<n;i++) printf("%c", str[i]);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}