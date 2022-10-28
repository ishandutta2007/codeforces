#include <bits/stdc++.h>
using namespace std;
queue < int > q1 , q2;
int n , k1 , k2 , temp , card1 , card2;
int main(){
    cin>>n;
    cin>>k1;
    while(k1--){
        cin>>temp;
        q1.push(temp);
    }
    cin>>k2;
    while(k2--){
        cin>>temp;
        q2.push(temp);
    }
    for(int steps = 1 ; steps <= 50000000 ; ++steps){
        card1 = q1.front();
        card2 = q2.front();
        q1.pop();
        q2.pop();
        if(card1 > card2){
            q1.push(card2);
            q1.push(card1);
        }
        else{
            q2.push(card1);
            q2.push(card2);
        }
        if(q1.empty()){
            printf("%d %d",steps , 2);
            return 0;
        }
        if(q2.empty()){
            printf("%d %d",steps , 1);
            return 0;
        }
    }
    printf("-1");
}