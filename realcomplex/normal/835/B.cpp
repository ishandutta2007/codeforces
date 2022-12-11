#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int num[10];

int main()
{
    int k;
    cin >> k;
    char s;
    int sum = 0;
    while(cin >> s){
        num[s-48]++;
        sum += s-48;
    }
    if(sum >= k){
        cout << 0;
    }
    else{
        int am = 0;
        int add = 9;
        for(int i = 0;i<10;i++){
            add = 9-i;
            for(int x = 0;x<num[i];x++){
                if(sum >= k){
                    break;
                }
                else{
                    sum += add;
                    am++;
                }
            }
            if(sum>=k){
                break;
            }
        }
        cout << am;
    }
    return 0;
}