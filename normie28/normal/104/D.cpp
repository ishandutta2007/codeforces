#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    long long n;
    long long k;
    int q;
    cin>>n>>k>>q;
    if(n%2==1){
        n--,k--;
    }
    for(int i=0;i<q;i++){
        long long x;
        cin>>x;
        if(x%2==0){
            long long x2 = x/2;
            long long num = n/2;
            if(num - x2<k)
                cout<<'X';
            else
                cout<<'.';
        }else{
            if(n%2==0&&x==n+1){
                if(k>=0)
                    cout<<'X';
 
                else{
                    cout<<'.';
                }
                continue;
            }
            long long num = n/2;
            long long kk = k-num;
            long long num2 = n-n/2;
            long long num3 = (x+1)/2;
            long long num4 = num2 - num3;
            if(num4<kk) cout<<'X';
            else cout<<'.';
        }
    }
}