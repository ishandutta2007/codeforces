#include <iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;
    n--;
    long long sum=1, pre2=0, pre1=1;
    int cur=1;
    while(n>sum){
        long long tmp=pre2+pre1;
        sum+=tmp;
        pre2=pre1;
        pre1=tmp;
        cur++;
    }
    if(n==sum) cout<<cur<<endl;
    else cout<<cur-1<<endl;
    return 0;
}