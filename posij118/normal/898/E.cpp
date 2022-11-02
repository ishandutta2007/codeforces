#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, dist, zero, dm, hm, mid, cnt;
    cnt=0;
    dist=0;
    zero=0;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<int> sq;
    sq.push_back(-5);
    for(int i=0; i*i<1100000000; i++){
        sq.push_back(i*i);
    }


    int num[n];
    for(int i=0; i<n; i++){
        dm=0;
        hm=sq.size();
        for(int j=0; j<20; j++){
            mid=(dm+hm)/2;
            if(sq[mid]>a[i]) hm=mid;
            else if(sq[mid]<a[i]) dm=mid;
        }

        if(sq[mid]<a[i]){
            num[i]=min(sq[mid+1]-a[i], a[i]-sq[mid]);
            if(num[i]==0) dist++;
            if(a[i]==0) zero++;
        }

        else if(sq[mid]>a[i]){
            num[i]=min(sq[mid]-a[i], a[i]-sq[mid-1]);
            if(num[i]==0) dist++;
            if(a[i]==0) zero++;
        }

        else{
            num[i]=min(sq[mid+1]-a[i], a[i]-sq[mid]);
            if(num[i]==0) dist++;
            if(a[i]==0) zero++;
        }
    }

    sort(num, num + n);
    if(dist<n/2){
        for(int i=dist; i<n/2; i++){
            cnt+=num[i];
        }
        cout << cnt;
    }

    else{
        for(int i=0; i<dist-n/2; i++){
            if(dist-zero>0){
                zero++;
                cnt++;
            }
            else cnt+=2;
        }

        cout << cnt;
    }

}