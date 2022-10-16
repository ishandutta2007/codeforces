#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N = 1e5 + 500;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;


string s;
int k,cr;

int main(){
    cin >> k >> s;
    for(int i = 0;i<s.size();i++){
        cr += s[i] - '0';
    }
    if(cr < k){
        sort(s.begin(),s.end());
        int sl = 0;
        for(int i = 0;i<s.size();i++){
            cr += 9 - s[i] + '0';
            sl++;
            if(cr >= k ) break;
        }
        printf("%d\n",sl);
        return 0;
    }
    printf("0\n");
}