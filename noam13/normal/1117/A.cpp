#include <iostream>
#include <vector>
typedef unsigned long long ull;
using namespace std;

int main()
{
    int n,in;
    cin >> n;
    int m;
    cin >> m;
    int len=1;
    int mlen=1;
    for(int i=1;i<n;i++){
        cin >> in;
        if (in>m){
            len=1;
            mlen=1;
            m=in;
        }
        else if (in==m){
            len++;
        }
        else {
            mlen=max(len,mlen);
            len=0;
        }
    }
    mlen=max(len,mlen);
    cout << mlen <<endl;
    return 0;
}