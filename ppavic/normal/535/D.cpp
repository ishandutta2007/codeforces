#include <cstdio>
#include <cstring>
#include <iostream>


using namespace std;

char a[1000000+5];
char b[1000000+5];
char x[1000000+5];
int l,c,cnt = 0;

inline long long int mul(long long int a,long long int b){
    long long int sol = a*b;
    if(sol > 1000000007) return sol%1000000007;
    return sol;
}

inline long long int pot(long long int a,long long int b){
    long long int sol = 1;
    while(b!=0){
        if(b&1) sol=mul(a,sol);
        b = b>>1;
        a = mul(a,a);
    }
    return sol;
}

int main(){
    cin >> l >> c >> x;
    int pos = 0,cur[1000005];
    int len = strlen(x);
    for(int i = 0;i<c;i++){
        cin >> cur[i];
        cur[i]--;
        pos = max(cur[i],pos);
        for(int j = pos;j<cur[i] + len;j++){
           a[j] = x[j-cur[i]];
           cnt++;
           pos++;
        }
    }
    pos = l;
    for(int i = c-1;i>=0;i--){
        pos = min(cur[i]+len,pos);
        for(int j = pos;j>=cur[i];j--){
            b[j] = x[j - cur[i]];
            pos--;
        }
    }
    for(int i = 0;i<l;i++){
        if(a[i] != b[i]){
            printf("0\n");return 0;
        }
    }
    cout << pot(26,l-cnt) << endl;

}