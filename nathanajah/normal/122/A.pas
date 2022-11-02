var
n:longint;
i:longint;
a:array[1..100] of longint;
count:longint;
bisa:boolean;

begin
a[1]:=4;
a[2]:=7;
a[3]:=44;
a[4]:=47;
a[5]:=74;
a[6]:=77;
a[7]:=444;
a[8]:=447;
a[9]:=474;
a[10]:=477;
a[11]:=744;
a[12]:=747;
a[13]:=774;
a[14]:=777;
count:=14;
readln(n);
bisa:=false;
for i:=1 to count do
	bisa:=bisa OR (n mod a[i]=0);
if bisa then writeln('YES') else writeln('NO');
	
end.