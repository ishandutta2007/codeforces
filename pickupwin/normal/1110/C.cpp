
#include <cstdio>

int Q;
int A;
int Ans[33];

int main(){
	
	Ans[2]=1;
	Ans[3]=1;
	Ans[4]=5;
	Ans[5]=1;
	Ans[6]=21;
	Ans[7]=1;
	Ans[8]=85;
	Ans[9]=73;
	Ans[10]=341;
	Ans[11]=89;
	Ans[12]=1365;
	Ans[13]=1;
	Ans[14]=5461;
	Ans[15]=4681;
	Ans[16]=21845;
	Ans[17]=1;
	Ans[18]=87381;
	Ans[19]=1;
	Ans[20]=349525;
	Ans[21]=299593;
	Ans[22]=1398101;
	Ans[23]=178481;
	Ans[24]=5592405;
	Ans[25]=1082401;
	
	scanf("%d", &Q);
	
	for(int i=1;i<=Q;++i){
		scanf("%d", &A);
		for(int j=2;j<=25;++j){
			if(A==(1<<j)-1){
				printf("%d\n", Ans[j]);
				A=0;
				break;
			}
		}
		if(A>0){
			for(int j=2;j<=25;++j){
				if(A<(1<<j)-1){
					printf("%d\n", (1<<j)-1);
					break;
				}
			}
		}
	}
	
	return 0;
}

/*
#include <cstdio>

int gcd(int a, int b){
	return (b==0)?a:gcd(b, a%b);
}

int A;

int main(){
	
	int t;
	
	scanf("%d", &t);
	
	A=(1<<t)-1;
	
	int Ans=0;
	
	for(int i=1, g;i<A;++i){
		g=gcd(A&i, A^i);
		if(g>Ans)	Ans=g;
	}
	
	printf("\tAns[%d]=%d;\n", t, Ans);
	
	
	return 0;
}
*/

/*
#include <cstdio>

int A;

int Gcd=0, Val=0;

int gcd(int a, int b){
	printf("%d %d\n", a, b);
	return (b==0)?a:gcd(b, a%b);
}

void Update(int B){
	int g=gcd(A^B, A&B);
	if(g>Gcd){
		Gcd=g;
		Val=B;
	}
}

int main(){
	
	int t;
	
	scanf("%d", &A);
	
	//A=(1<<t)-1;
	
	for(int i=1;i<A;++i){
		Update(i);
	}
	
	printf("\tAns[%d]=%d;\n", t, Val);
	
	
	return 0;
}
*/