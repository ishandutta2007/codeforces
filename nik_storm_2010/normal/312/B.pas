var
    a,b,c,d,inf,ans:double;



begin

  readln(a,b,c,d); inf:=100000000; ans:=0;
  while inf>1 do
    begin
      ans:=ans+inf*(a/b);
      inf:=inf-inf*(a/b);
      inf:=inf-inf*(c/d);
    end;
  writeln((ans/100000000):0:10);

end.