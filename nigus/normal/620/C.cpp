#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;

std::vector<ll> A;
std::vector<int> B;
std::vector<ll> A2;

int main()
{
    ll c1,c2,c3;
    int n,m,a,b,c,d;

    //std::cin >> n;
    scanf("%d" , &n);
    for(c1=0;c1<n;c1++)
    {
        scanf("%d", &a);
        A.push_back(a);
        A2.push_back(a);
    }
    std::sort(A2.begin(),A2.end());
    B.push_back(0);
    int ans = 0;
    bool fail = 1;
    /*
    for(c1=0;c1<n-1;c1++)
    {
        if(A2[c1] == A2[c1+1])

    }
    */
    ll ma = 0;
    std::map<ll,ll> M;
    for(c1=0;c1<n;c1++){
        //cout << c1 << " ";
        if(fail == 1){
            M.clear();
            M[A[c1]] = 1;
            fail = 0;
            ma = 0;
        }
        else{

            if(M.find(A[c1]) != M.end()){
                M[A[c1]]++;
            }
            else{
                M[A[c1]] = 1;
            }
            if(M[A[c1]] == 2){
                fail = 1;
                B.push_back(c1+1);
                ans++;
                //c1--;

            }

        }

    }
    if(ans == 0){
            printf("-1\n");
            //cout << "-1\n";
    }else{
        printf("%d\n",ans);
       // cout << ans << "\n";
    for(c1 = 0; c1 < ans;c1++){
        if(c1 == ans-1){b = n;}else{b = B[c1+1];}
        //cout << B[c1]+1 << " " << b << "\n";
        printf("%d %d\n",B[c1]+1,b);

    }

}
    return 0;
}