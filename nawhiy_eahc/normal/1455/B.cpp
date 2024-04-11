#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int ans=1;
        while(true){
            if(n == ans*(ans-1)/2-1) break;
            if(n <= ans*(ans+1)/2 && n != ans*(ans+1)/2-1) break;
            ans++;
        }
        printf("%d\n", ans);
    }
}