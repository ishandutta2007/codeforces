var
    n,a,b,c,i,j,ans:longint; ost,z:extended;


begin

  readln(n,a,b,c); ans:=0;
  for i:=0 to a do
    for j:=0 to b do
      begin
        ost:=n-((i*0.5)+(j));
        if ost>=0 then
          begin
            z:=ost/2;
            if (frac(z)=0) and (z<=c) then inc(ans);
          end;
      end;
  writeln(ans);

end.