#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, q;
        scanf("%d %d", &n, &q);
        int s[102];
        for(int i=0;i<n;i++){
            scanf("%1d", &s[i]);
        }

        for(int i=1;i<=q;i++){
            int l, r;
            scanf("%d %d", &l, &r);
            l--; r--;
            bool b = false;

            for(int i=0;i<l;i++){
                if(s[i] == s[l]) b = true;
            }
            for(int i=r+1;i<n;i++){
                if(s[i] == s[r]) b = true;
            }
            if(b) printf("YES\n");
            else printf("NO\n");
        }
    }
}