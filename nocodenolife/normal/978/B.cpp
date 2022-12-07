#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin>>n;
    int answer =0;
    int consec =0;
    for(int i=0;i<n;i++)
    {
        char hehe;
        cin>>hehe;
        if(hehe=='x')
            consec++;
        else
        {
            if(consec>2)
                answer+=consec-2;
            consec=0;
        }
    }
    if(consec>2)
        answer+=consec-2;
    cout<<answer<<endl;
    
    return 0;
}