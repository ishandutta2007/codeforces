#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool flag = false;
        for(int i=0;i<=2020;i++){
            if(n - 2021 * i < 0) break;
            if((n - 2021 * i)%2020 == 0){
                printf("YES\n");
                flag = true;
                break;
            }
        }
        if(!flag) printf("NO\n");
    }
}