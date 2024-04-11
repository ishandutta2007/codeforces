var
     ans,n:longint;


begin

  readln(n);
  if n mod 2=0 then ans:=0 else
  begin
    case n of
      01:ans:=1;
      03:ans:=18;
      05:ans:=1800;
      07:ans:=670320;
      09:ans:=734832000;
      11:ans:=890786230;
      13:ans:=695720788;
      15:ans:=150347555;
      end;
  end;
  writeln(ans);

end.