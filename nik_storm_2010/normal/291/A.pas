var
    a:array[1..1000] of longint; used:array[1..1000] of boolean; ans,kol,n,i,j:longint;


begin

  readln(n); for i:=1 to n do read(a[i]);
  ans:=0;
  for i:=1 to n do
    if (used[i]=true) or (a[i]=0) then continue else
    begin
      kol:=0;
      for j:=i to n do
        if a[j]=a[i] then begin inc(kol); used[j]:=true; end;
      if kol>2 then begin writeln(-1); halt; end else if kol=2 then inc(ans);
    end;
  writeln(ans);

end.