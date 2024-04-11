program storm;
var ch1,ch2,n,i,a,sum:longint;

procedure inputdata;
begin
 readln(a);
end;

procedure perevod(chiclo,step:longint; var sum:longint);
begin
 sum:=0;
 while chiclo<>0 do
  begin
  sum:=sum+(chiclo mod step);
  chiclo:=chiclo div step;
  end;
end;

procedure nod(a,b:longint; var n:longint);
begin
 while (a<>0) and (b<>0) do
  if a>b then a:=a mod b
         else b:=b mod a;
 n:=a+b;
end;

procedure outputdata;
begin
 writeln(ch1,'/',ch2);
end;

begin
 inputdata; ch1:=0;
 for i:=2 to a-1 do
  begin
  perevod(a,i,sum);
  ch1:=ch1+sum;
  end;
 ch2:=a-2;
 nod(ch1,ch2,n);
 ch1:=ch1 div n;
 ch2:=ch2 div n;
 outputdata;
end.