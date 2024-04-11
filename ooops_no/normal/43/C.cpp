#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    int sum;
    cin>>x;
    int cnt1=0,cnt2=0,cnt3=0;
    for (int i = 0; i<x ; i++){
        int r;
        cin>>r;
        sum=0;
        while (r!=0){
            sum+=r%10;
            r/=10;
        }
        if (sum%3==1){
            cnt1+=1;
        }
        else if (sum%3==2){
            cnt2+=1;
        }
        else{
            cnt3+=1;
        }
    }
    cout<<cnt3/2+min(cnt1,cnt2);
}