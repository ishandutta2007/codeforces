#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
map<string,int> XD;
char all[12][3]={
    "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"
};
int gn(){
    char tmp[3];
    scanf("%s",tmp);
    return XD[tmp];
}
int a[3];
bool ismajor(){
    return a[1]==(a[0]+4)%12&&a[2]==(a[1]+3)%12;
}
bool isminor(){
    return a[1]==(a[0]+3)%12&&a[2]==(a[1]+4)%12;
}
int main(){
    int i;
    for(i=0;i<12;i++)XD[all[i]]=i;
    for(i=0;i<3;i++)a[i]=gn();
    sort(a,a+3);
    do{
	if(ismajor()){
	    puts("major");
	    return 0;
	}
	if(isminor()){
	    puts("minor");
	    return 0;
	}
    }while(next_permutation(a,a+3));
    puts("strange");
}