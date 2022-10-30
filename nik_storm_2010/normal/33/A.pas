program storm;
var a:array[1..1050] of longint;
    i,n,m,k,kol,sum:longint;


procedure inputdata;
var i,ch1,ch2:longint;
begin
 readln(n,m,k);
 for i:=1 to n do
  begin
  readln(ch1,ch2);
  if a[ch1]>ch2 then a[ch1]:=ch2;
  end;
end;

procedure outputdata;
begin
 writeln(kol);
end;

begin
 for i:=1 to 1000 do a[i]:=MaxLongint; kol:=0; sum:=0;
 inputdata;
 for i:=1 to m do sum:=sum+a[i];
 if sum>=k then kol:=k
           else kol:=sum;
 outputdata;
end.