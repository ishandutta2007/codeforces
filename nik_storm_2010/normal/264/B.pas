var
    a,d,f:array[1..100000] of longint; answer,pred,tek,n,i,j:longint;


begin

  readln(n); answer:=0;
  for tek:=1 to n do
    begin
      read(a[tek]); pred:=round(sqrt(a[tek])); f[tek]:=-maxlongint;
      for i:=1 to pred do
        if a[tek] mod i=0 then
        begin
          j:=a[tek] div i;
          if (i<>1) and (d[i]+1>f[tek]) then f[tek]:=d[i]+1;
          if (j<>1) and (d[j]+1>f[tek]) then f[tek]:=d[j]+1;
        end;
      for i:=1 to pred do
        if a[tek] mod i=0 then
        begin
          j:=a[tek] div i;
          if (i<>1) then d[i]:=f[tek]; if (j<>1) then d[j]:=f[tek];
        end;
      if answer<f[tek] then answer:=f[tek];
    end;
  if (n=1) then writeln(1) else writeln(answer);

end.