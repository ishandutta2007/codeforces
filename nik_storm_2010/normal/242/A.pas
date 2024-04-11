var
    ans:array[1..10000,1..2] of longint; answer,x,y,a,b,i,j:longint;


begin

  readln(x,y,a,b); answer:=0;
  for i:=a to x do
    for j:=b to y do
    if i>j then
      begin
        inc(answer);
        ans[answer,1]:=i; ans[answer,2]:=j;
      end;
  writeln(answer);
  for i:=1 to answer do writeln(ans[i,1],' ',ans[i,2]);

end.