var
    a,ans:array[1..10000] of longint; answer,n,m,k,i,j:longint;


procedure add(nom:longint);
  var i:longint;
begin
  for i:=1 to n do inc(a[nom+i-1]);
end;


begin

  readln(n,m,k); answer:=0;
  for i:=1 to n+m do
    begin
      if a[i]<k then
        begin
          for j:=1 to k-a[i] do
            begin
              add(i); inc(answer);
              ans[answer]:=i;
            end;
        end;
      if (i<>n+m) and (a[i+1]=0) then
        begin
          add(i); inc(answer);
          ans[answer]:=i;
        end;
    end;
  if a[n+m+1]=0 then begin inc(answer); ans[answer]:=n+m; end;

  writeln(answer);
  for i:=1 to answer do write(ans[i],' ');

end.