#include<iostream>
#include<vector>
#include<algorithm>

#include<bits/stdc++.h>

using namespace std;

char buf[100002];
string a;
string b;
string c;
const int MAX=27;
int cnt[MAX];
int bb[MAX];
int cc[MAX];
int main(){
    scanf("%s", buf);
    a = buf;
    scanf("%s", buf);
    b = buf;
    scanf("%s", buf);
    c = buf;
    for (int i = 0; i < a.size(); i++){
        cnt[a[i] - 'a']++;
    }
    for (int i = 0; i < b.size(); i++){
        bb[b[i] - 'a']++;
    }
    for (int i = 0; i < c.size(); i++){
        cc[c[i] - 'a']++;
    }
    int B = 0;
    int C = 0;
    {
        int mint = INT_MAX;
        for (int k = 0; k < MAX; k++){
            if (bb[k]){
                mint = min(mint, cnt[k] / bb[k]);
            }
        }
        B = mint;
        for (int k = 0; k < MAX; k++){
            cnt[k] -= bb[k] * mint;
        }
    }
    {
        int mint = INT_MAX;
        for (int k = 0; k < MAX; k++){
            if(cc[k]){
                mint = min(mint, cnt[k] / cc[k]);
            }
        }
        C = mint;
        for (int k = 0; k < MAX; k++){
            cnt[k] -= cc[k] * mint;
        }
    }
    int ans = B + C;
    int ab = B;
    int ac = C;
    for (int i = B; i > 0; i--){
        for (int k = 0; k < MAX; k++){
            cnt[k] += bb[k];
        }
        int kb = i-1;
        int mint = INT_MAX;
        for (int k = 0; k < MAX; k++){
            if (cc[k]){
                mint = min(mint, cnt[k] / cc[k]);
            }
        }
        C += mint;
        for (int k = 0; k < MAX; k++){
            cnt[k] -= cc[k] * mint;
        }
        if (kb + C > ans){
            ans = kb + C;
            ab = kb;
            ac = C;
        }
    }
    for (int i = 0; i < ab; i++){
        printf("%s", b.c_str());
    }
    for (int i = 0; i < ac; i++){
        printf("%s", c.c_str());
    }
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < a.size(); i++){
        cnt[a[i] - 'a']++;
    }
    for (int i = 0; i < MAX; i++){
        cnt[i] -= bb[i] * ab;
        cnt[i] -= cc[i] * ac;
        string k1 = "f";
        k1[0] = i + 'a';
        while (cnt[i]--){
            printf("%s", k1.c_str());
        }
    }
    puts("");
    return 0;
}