#include <bits/stdc++.h>
using namespace std;

int main(){

    int a, b;
    cin>>a>>b;
    if(b>a) cout<<0<<endl;
    else if(b==a)   cout<<"infinity"<<endl;
    else{
        a-=b;
        int counter=0;
        for(int i=1;i*i<=a;i++){
            if(a%i==0){
                if(i>b) counter++;
                if(a/i > b) counter++;
            }
        }
        //cout<< ((float)sqrt(a)*sqrt(a)==a) <<endl;
        if((float)sqrt(a)*sqrt(a)==a && sqrt(a)>b)  counter--;
        cout<<counter<<endl;
    }

    //system("pause");
    return 0;
}