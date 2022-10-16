#include <iostream>
using namespace std;
int k, num[500];
int main(){
    ios_base::sync_with_stdio(false);
    cin>>k;
    for(int i=1; i<=448; i++)
        num[i]=i*(i-1)/2;
    if(!k){
        cout<<"a"<<endl;
        return 0;
    }
    int cur=448;
    char ch='a';
    while(k){
        for(int i=cur; i>0; i--){
            if(k>=num[i]){
                k-=num[i];
                for(int j=0; j<i; j++)
                    cout<<ch;
                ch++;
                cur=i;
                break;
            }
        }
    }
    cout<<endl;
    return 0;
}