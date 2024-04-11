var
    xa,xb,xc,ya,yb,yc:extended; gora,gorc,vera,verc:char;


begin

  readln(xa,ya); readln(xb,yb); readln(xc,yc);
  if xa=xb then gora:='=' else if xa<xb then gora:='<' else gora:='>';
  if ya=yb then vera:='=' else if ya<yb then vera:='<' else vera:='>';
  if xc=xb then gorc:='=' else if xc<xb then gorc:='<' else gorc:='>';
  if yc=yb then verc:='=' else if yc<yb then verc:='<' else verc:='>';
  if vera='<' then
    begin
      case gora of
        '<':begin
              if verc='<' then writeln('RIGHT') else
              if gorc='<' then writeln('LEFT') else writeln('TOWARDS');
            end;
        '>':begin
              if gorc='>' then writeln('RIGHT') else
              if verc='<' then writeln('LEFT') else writeln('TOWARDS');
            end;
        '=':begin
              if gorc='<' then writeln('LEFT') else
              if gorc='>' then writeln('RIGHT') else writeln('TOWARDS');
            end;
        end;
    end;
  if vera='>' then
    begin
      case gora of
        '<':begin
              if verc='>' then writeln('LEFT') else
              if gorc='<' then writeln('RIGHT') else writeln('TOWARDS');
            end;
        '>':begin
              if verc='>' then writeln('RIGHT') else
              if gorc='>' then writeln('LEFT') else writeln('TOWARDS');
            end;
        '=':begin
              if gorc='<' then writeln('RIGHT') else
              if gorc='>' then writeln('LEFT') else writeln('TOWARDS');
            end;
        end;
    end;
  if vera='=' then
    begin
      case gora of
        '<':begin
              if verc='>' then writeln('LEFT') else
              if verc='<' then writeln('RIGHT') else writeln('TOWARDS');
            end;
        '>':begin
              if verc='>' then writeln('RIGHT') else
              if verc='<' then writeln('LEFT') else writeln('TOWARDS');
            end;
        end;
    end;

end.