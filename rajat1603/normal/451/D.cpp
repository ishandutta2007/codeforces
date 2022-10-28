#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(){
    //int t;
   // scanf("%d",&t);
   // while(t--){
        string s;
        int k=0;
        cin>>s;
        k=s.size();
        //fast input **** yeah
        long long even0=0,even1=0,odd0=0,odd1=0,ansod=0,ansev=0;
        for(int j=0;j<k;j++){
            ansod++;
            int i =j+1;
            if(i%2==1){
                if(s[j]=='a'){
                    ansod+=odd1;
                    ansev+=even1;
                    odd1++;
                }
                else{
                    ansod+=odd0;
                    ansev+=even0;
                    odd0++;
                }
            }
            else{
                if(s[j]=='a'){
                    ansod+=even1;
                    ansev+=odd1;
                    even1++;
                }
                else{
                    ansod+=even0;
                    ansev+=odd0;
                    even0++;
                }
                
            }
        }
        cout<<ansev<<" "<<ansod;
    //}
}