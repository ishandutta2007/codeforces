#include <iostream>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        map<int, int> mini;
        vector<int> have;
        int ans = 0;

        for(int i=1;i<=n;i++){
            int a;
            scanf("%d", &a);
            int sqta = sqrt(a);
            for(int j=sqta;j>=1;j--){
                if(a%(j*j) == 0){
                    mini[a/(j*j)]++;
                    ans = max(ans, mini[a/(j*j)]);
                    have.push_back(a/(j*j));
                    break;
                }
            }
        }

        int ans2 = 0;

        for(auto i : have){
            if(mini[i]%2 == 0 && i != 1){
                mini[1] += mini[i];
                mini[i] = 0;
                ans2 = max(ans2, mini[1]);
            }
            else ans2 = max(ans2, mini[i]);
        }

        int q;
        scanf("%d", &q);

        for(int i=1;i<=q;i++){
            long long k;
            scanf("%lld", &k);
            if(k == 0) printf("%d\n", ans);
            else printf("%d\n", ans2);
        }
    }
}