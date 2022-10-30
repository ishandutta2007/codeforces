#include <stdio.h>
#include <iostream>
using namespace std;
int a[50][50];
int main()
{
    int n;
    cin>>n;
    int br=0, tmp=0, ti, tj;
    char ch;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin>>ch;
            a[i][j]=ch-'0';
            if(tmp==0 && ch!='0'){
                    tmp=a[i][j];
                    ti=i; tj=j;
            }
            if(ch!='0') br++;
        }
    }
    if(tmp==1){
        int cur=a[ti][tj+1];
        if(cur!=2){
             cout << "No";
            return 0;
        }
        int j;
        for(j=tj+1; j<n-1 && a[ti][j]==2 ; ++j){}
        if(a[ti][j]!=1){
               // cout<< "puko na gornju";
             cout << "No";
            return 0;
        }
        int i;
        for(i=ti+1; i<n-1 && a[i][tj]==2 ; ++i){}
        if(a[i][tj]!=1){
                //cout << "puko na levu";
             cout << "No";
            return 0;
        }
        if((i-ti+1)*(j-tj+1)!=br){
             //   cout << "puko na br "<< (i-ti)*(j-tj);
             cout << "No";
            return 0;
        }
        int i1, j1;
        for(i1=ti+1; i1<n-1 && a[i1][j]==2 ; ++i1){}
        if(a[i1][j]!=1){
             //   cout << "puko na desnu";
             cout << "No";
            return 0;
        }
        for(j1=tj+1; j1<n-1 && a[i][j1]==2 ; ++j1){}
        if(a[i][j1]!=1){
              //  cout << "puko na donju granicu";
            cout << "No";
            return 0;
        }
        for(int x=ti+1; x<i; ++x){
            for(int y=tj+1; y<j; ++y){
                if(a[x][y]!=4){
             //           cout << "puko na cetvorke";
                     cout << "No";
                    return 0;
                }
            }
        }
        cout << "Yes";
        return 0;
    }
    else{
       // cout << "puko na nije 1\n";
        cout << "No";
    }
    return 0;
}