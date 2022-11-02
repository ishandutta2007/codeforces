var
    a,ans:array[1..100] of longint; kol,n,i:longint; have1,have2:boolean;


procedure add(nom:longint);
begin
  inc(kol); ans[kol]:=a[nom];
end;


begin

  readln(n); for i:=1 to n do read(a[i]);
  kol:=0; have1:=false; have2:=false;
  for i:=1 to n do
    begin
      if a[i]=0 then add(i);
      if (have1=false) and (0<a[i]) and (a[i]<10) then begin add(i); have1:=true; end;
      if (have2=false) and (9<a[i]) and (a[i]<100) and (a[i] mod 10=0) then begin add(i); have2:=true; end;
      if a[i]=100 then add(i);
    end;
  if (have1=false) and (have2=false) then
    begin
      for i:=1 to n do
        if (a[i]<>0) and (a[i]<>100) then begin add(i); break; end;
    end;
  writeln(kol);
  for i:=1 to kol do write(ans[i],' ');

end.