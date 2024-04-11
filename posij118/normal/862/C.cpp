#include <bits/stdc++.h>
using namespace std;

int n, x, tr;
int a[65536];
vector<int> xur;

void four_more(int ptr){
    while(1){
    if(a[ptr]==0){
        a[ptr]=1;
        xur.push_back(ptr);
        xur.push_back(ptr+65536);
        xur.push_back(ptr+131072);
        xur.push_back(ptr+196608);
        break;
    }

    else ptr++;

    }
}

int main(){
    cin >> n >> x;

    for(int i=0; i<65536; i++){
        a[i]=0;
    }
    tr=0;

    if(n%4==1){
        xur.push_back(x);
        a[x%65536]=1;
        for(int i=0; i<n/4; i++){
            four_more(tr);
        }
    }

    else if(n%4==2 && x!=0){
        xur.push_back(0);
        xur.push_back(x);
        a[0]=1;
        a[x%65536]=1;
        for(int i=0; i<n/4; i++){
            four_more(tr);
        }
    }

    else if(n%4==2 && n>2){
        xur.push_back(7);
        xur.push_back(12);
        xur.push_back(3);
        xur.push_back(11);
        xur.push_back(5);
        xur.push_back(6);
        a[3]=1;
        a[7]=1;
        a[5]=1;
        a[6]=1;
        a[11]=1;
        a[12]=1;

         for(int i=0; i<n/4-1; i++){
            four_more(tr);
        }
    }

    else if(n%4==3 || n%4==0){
        if(x>3){
            xur.push_back((((x/2)*4)+1-x));
            xur.push_back(2);
            xur.push_back(3);
            a[(((x/2)*4)+1-x)%65536]=1;
            a[2]=1;
            a[3]=1;
            if(n%4==0){
                xur.push_back(0);
                a[0]=1;
            }

            for(int i=0; i<(n-1)/4; i++){
                four_more(tr);
            }
        }

        else if(x==0){
            xur.push_back(6);
            xur.push_back(3);
            xur.push_back(5);
            a[6]=1;
            a[5]=1;
            a[3]=1;
            if(n%4==0){
                xur.push_back(0);
                a[0]=1;
            }
             for(int i=0; i<(n-1)/4; i++){
                four_more(tr);
            }

        }

        else if (x==1) {
            xur.push_back(7);
            xur.push_back(3);
            xur.push_back(5);
            a[7]=1;
            a[5]=1;
            a[3]=1;
            if(n%4==0){
                xur.push_back(0);
                a[0]=1;
            }
             for(int i=0; i<(n-1)/4; i++){
                four_more(tr);
            }
        }

        else if (x==2) {
            xur.push_back(15);
            xur.push_back(14);
            xur.push_back(3);
            a[15]=1;
            a[14]=1;
            a[3]=1;
            if(n%4==0){
                xur.push_back(0);
                a[0]=1;
            }
             for(int i=0; i<(n-1)/4; i++){
                four_more(tr);
            }
        }

        else if (x==3) {
            xur.push_back(15);
            xur.push_back(14);
            xur.push_back(2);
            a[15]=1;
            a[14]=1;
            a[2]=1;
            if(n%4==0){
                xur.push_back(0);
                a[0]=1;
            }
             for(int i=0; i<(n-1)/4; i++){
                four_more(tr);
            }
        }


    }

    else cout << "NO";

    if(xur.size()){
        cout << "YES" << endl;
        for(int i=0; i<xur.size(); i++){
            cout << xur[i] << " ";
        }
    }

}