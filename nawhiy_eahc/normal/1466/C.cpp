#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int cnt = 0;
        for(int i=1;i<n;i++){
            int t = 0;
            if(s[i] == s[i-1]){
                s[i] = 'a';
                while(s[i] == s[i-1] || (i > 1 && s[i] == s[i-2]) || (i < n-1 && s[i] == s[i+1]) || (i < n-2 && s[i] == s[i+2])) s[i]++;
                t = 1;
            }
            if(s[i] == s[i-2]){
                s[i] = 'a';
                while(s[i] == s[i-1] || (i > 1 && s[i] == s[i-2]) || (i < n-1 && s[i] == s[i+1]) || (i < n-2 && s[i] == s[i+2])) s[i]++;
                t = 1;
            }

            cnt += t;
        }

        printf("%d\n", cnt);
    }
}