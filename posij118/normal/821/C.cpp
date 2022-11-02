#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, a, pocet, ptr, skap, rem, x, pptr;
    a=0;
    pocet=0;
    ptr=-1;
    rem=0;
    cin >> n;

    string commies[2*n+1];
    commies[2*n]="akdj";
    int perm[n];

    for(int i=0; i<2*n; i++){
        cin >> commies[i];
        if(commies[i]=="add"){
            cin >> perm[a];
            a++;
        }
    }

    for(int i=0; i<2*n+1; i++){
        if(commies[i]=="add"){
            ptr++;
        }

        else if (commies[i]=="remove") {
            rem++;
            a=1;
            while(commies[i+1]=="remove"){
                i++;
                a++;
                rem++;

            }

            x=0;
            pptr=ptr;
            skap=0;
            for(int j=i-a; j>i-2*a; j--){

               if(commies[j]=="add"){
                    x++;
                    if(perm[pptr]!=rem-a+x){
                        skap=1;
                        break;
                    }
                    pptr--;
               }

               else break;
            }
            if(skap==1){
                pocet++;
            }
        }
    }

    cout << pocet << endl;
}