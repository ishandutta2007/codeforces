#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    if(b<=0){
        for(int j = 0;j<abs(b);j++){
            a--;
            if(a == 0){
                a = n;
            }
        }
        cout << a;
    }
    else{
        for(int j = 0;j<abs(b);j++){
            a++;
            if(a == n+1){
                a = 1;
            }
        }
        cout << a;
    }
    return 0;
}