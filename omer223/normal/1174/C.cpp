#include <iostream>
#include <algorithm>

using namespace std;

const int sz=1e5+5;
int col[sz];

int main() {
    int n,cnt=0;
    cin>>n;
    for(int i = 2; i <=n;i++){
        if(!col[i]){
            cnt++;
            col[i]=cnt;
            for(int j = 2 * i; j <= n; j+=i){
                if(!col[j])col[j]=cnt;
            }
        }
        cout<<col[i]<<" ";
    }
    cout<<endl;
}