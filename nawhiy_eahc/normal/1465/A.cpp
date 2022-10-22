#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        string s;
        cin >> s;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i] == ')') cnt++;
            else cnt = 0;
        }
        if(cnt *2 <= n) printf("No\n");
        else printf("Yes\n");
    }
}