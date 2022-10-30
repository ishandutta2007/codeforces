#include <iostream>
#include <algorithm>
using namespace std;


int arr[2005];

int main() {
    int n;
    cin>>n;
    for(int i =0;i<2*n;i++)cin>>arr[i];
    sort(arr,arr+2*n);
    if(arr[0]==arr[2*n-1]){
        cout<<-1<<endl;
    }
    else {
        for(int i =0;i<2*n;i++)cout<<arr[i] << " ";
        cout<<endl;
    }
}