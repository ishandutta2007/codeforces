var
    a,b,c,x1,x2,d:extended;


begin

  readln(a,b,c);
  if a=0 then
    begin
      if (b=0) or (c=0) then
        begin
          if (b=0) and (c=0) then
            begin
              writeln(-1);
            end
              else
            begin
              if (b=0) then
                begin
                  writeln(0);
                end
                  else
                begin
                  writeln(1); writeln(0);
                end;
            end;
        end
          else
        begin
          x1:=(-c)/b;
          writeln(1); writeln(x1:0:6);
        end;
    end
      else
    begin
      d:=(b*b)-(4*a*c);
      if d>0 then
        begin
          x1:=((-b)+sqrt(d))/(2*a); x2:=((-b)-sqrt(d))/(2*a); writeln(2);
          if x1>x2 then begin writeln(x2:0:6); writeln(x1:0:6); end
            else begin writeln(x1:0:6); writeln(x2:0:6); end;
        end
          else
        begin
          if d=0 then
            begin
              x1:=(-b)/(2*a);
              writeln(1); writeln(x1:0:6);
            end
              else
            begin
              writeln(0);
            end;
        end;
    end;

end.