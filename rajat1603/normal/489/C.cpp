#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mp make_pair
#define A first
#define B second
#define MIN (1<<31)
#define MAX (1<<31) - 1
#define MOD 1000000007
using namespace std;

#define N 100005

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m,s;
    cin>>m>>s;
    int orig=s;
    if(m==1 && s==0){
        cout<<"0 0"<<endl;
        return 0;
    }
    if(s>(m*9) || s==0){
        cout<<"-1 -1"<<endl;
        return 0;
    }
    //m is the length and s is the sum to be made.
    for(int i=1;i<=m;i++){
        if(i==1){
            if((m-i)*9>=(s-1)){ 
                cout<<1;
                s--;
            }
            else if(s-((m-i)*9)<=9){
                cout<<(s-((m-i)*9));
                s-=(s-((m-i)*9));   
            }
        }
        else{
            if((m-i)*9>=s)  cout<<0;
            else if(s-((m-i)*9)<=9){
                cout<<(s-((m-i)*9));
                s-=(s-((m-i)*9));   
            }
        }
    }
    s=orig;
    cout<<" ";
    for(int i=1;i<=m;i++){
        if(s>=9){
            cout<<9;
            s-=9;
        }
        else{
            cout<<s;
            s=0;
        }
    }

    return 0;
}