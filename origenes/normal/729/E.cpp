#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int main(){
    int n, s, cnt=0, err=0;
    cin>>n>>s;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    if(v[s-1]) err++;
    v.erase(v.begin()+s-1);
    sort(v.begin(), v.end());
    int curshouldbe=1;
    int i=0;
    n--;
    while(i<n){
        if(v[i]<curshouldbe) {i++; cnt++; err++; continue;}
        if(v[i]==curshouldbe) {i++; continue;}
        int tmp;
        tmp=(!i)?0:v[i-1];
        if(v[i]-tmp==1) curshouldbe++;
        else{
            if(cnt>=v[i]-tmp-1) cnt-=v[i]-tmp-1, curshouldbe=v[i];
            else{
            int gap=v[i]-tmp-1-cnt;
                if(n-1-i>=gap){
                    err+=gap;
                    n-=gap;
                    curshouldbe=v[i];
                    cnt=0;
                }else{
                    err+=n-i;
                    break;
                }
            }
        }
        i++;
    }
    cout<<err<<endl;
    return 0;
}